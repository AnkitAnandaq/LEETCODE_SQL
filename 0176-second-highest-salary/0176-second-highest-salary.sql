SELECT 
    (SELECT DISTINCT salary 
     FROM employee e 
     WHERE 2 = (
         SELECT COUNT(DISTINCT salary) 
         FROM employee e2 
         WHERE e.salary <= e2.salary
     )
     LIMIT 1) AS SecondHighestSalary;
