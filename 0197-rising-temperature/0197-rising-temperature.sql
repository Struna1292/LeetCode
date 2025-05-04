# Write your MySQL query statement below
SELECT w.id FROM weather w
    WHERE w.temperature > (SELECT w1.temperature FROM weather w1 WHERE w.recordDate = DATE_ADD(w1.recordDate, INTERVAL 1 DAY))