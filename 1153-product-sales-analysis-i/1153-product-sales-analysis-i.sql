# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price FROM sales s
    INNER JOIN product p ON p.product_id = s.product_id