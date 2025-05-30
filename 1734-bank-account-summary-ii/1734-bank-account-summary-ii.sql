# Write your MySQL query statement below
SELECT name, SUM(amount) as balance FROM users INNER JOIN transactions ON users.account = transactions.account
GROUP BY name
HAVING balance > 10000