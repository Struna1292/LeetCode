# Write your MySQL query statement below
SELECT DISTINCT p.Email FROM person p
    WHERE (SELECT COUNT(email) FROM person p1 WHERE p1.email = p.email) > 1;