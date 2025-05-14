# Write your MySQL query statement below
SELECT e.name FROM employee e
    WHERE 
    (SELECT COUNT(e1.managerid) FROM employee e1 WHERE e.id = e1.managerid) >= 5