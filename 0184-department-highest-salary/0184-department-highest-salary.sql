# Write your MySQL query statement below
SELECT d.name as "Department", e.name as "Employee", e.salary as "Salary" 
    FROM employee e INNER JOIN department d ON e.departmentId = d.id
    WHERE e.salary = (
        SELECT MAX(e1.salary) 
        FROM employee e1 INNER JOIN department d1 ON e1.departmentId = d1.id
        WHERE d1.name = d.name)