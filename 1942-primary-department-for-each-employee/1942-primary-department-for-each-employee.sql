# Write your MySQL query statement below
SELECT e.employee_id, e.department_id FROM employee e
    WHERE (SELECT COUNT(e1.department_id) FROM employee e1 WHERE e.employee_id = e1.employee_id) = 1 
    OR primary_flag = 'Y'