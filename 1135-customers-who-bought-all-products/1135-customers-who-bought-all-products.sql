# Write your MySQL query statement below
SELECT c.customer_id FROM customer c GROUP BY c.customer_id
    HAVING
    COUNT(DISTINCT product_key) 
    =
    (SELECT COUNT(*) FROM product)