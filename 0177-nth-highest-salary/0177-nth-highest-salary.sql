CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary
FROM employee e1
WHERE N = (
    SELECT COUNT(DISTINCT salary)
    FROM employee e2
    WHERE e1.salary <= e2.salary
)
LIMIT 1
  );
END