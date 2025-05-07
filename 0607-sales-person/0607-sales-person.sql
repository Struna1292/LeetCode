# Write your MySQL query statement below
SELECT sp.name FROM salesperson sp
    WHERE (SELECT COUNT(od1.order_id) FROM orders od1 
        INNER JOIN company cp1 ON cp1.com_id = od1.com_id
        INNER JOIN salesperson sp1 ON sp1.sales_id = od1.sales_id
        WHERE sp1.name = sp.name AND cp1.name = "RED") = 0