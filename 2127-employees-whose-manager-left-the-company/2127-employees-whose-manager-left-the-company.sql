# Write your MySQL query statement below
SELECT e.employee_id FROM employees e 
    WHERE e.manager_id IS NOT NULL AND (SELECT COUNT(e1.employee_id) FROM employees e1 WHERE e1.employee_id = e.manager_id) = 0
    AND e.salary < 30000 
    ORDER BY 1
