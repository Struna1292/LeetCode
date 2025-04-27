# Write your MySQL query statement below
SELECT e.name as "Employee" FROM employee e
    WHERE e.salary > (SELECT salary FROM employee WHERE id = e.managerid)