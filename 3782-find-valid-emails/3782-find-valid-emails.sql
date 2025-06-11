# Write your MySQL query statement below
SELECT user_id, email FROM users
WHERE email REGEXP '^[a-z|A-Z|0-9|_]*@[a-z|A-Z]*\.com'
ORDER BY user_id ASC;