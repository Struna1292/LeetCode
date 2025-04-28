# Write your MySQL query statement below
SELECT a.player_id, a.event_date as "first_login" FROM activity a
    WHERE a.event_date = (
        SELECT MIN(a1.event_date) FROM activity a1
            WHERE a.player_id = a1.player_id
    )