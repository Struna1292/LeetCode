# Write your MySQL query statement below
SELECT tab.class FROM 
    (SELECT class, COUNT(student) FROM courses GROUP BY class HAVING COUNT(student) >= 5) as tab