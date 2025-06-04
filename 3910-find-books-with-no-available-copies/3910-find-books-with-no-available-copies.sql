# Write your MySQL query statement below
SELECT tab.book_id, tab.title, tab.author, tab.genre, tab.publication_year, tab.current_borrowers FROM 
(SELECT lb.book_id, title, author, genre, publication_year, COUNT(*) as current_borrowers, total_copies
    FROM library_books lb INNER JOIN borrowing_records br ON lb.book_id = br.book_id
    WHERE return_date IS NULL
    GROUP BY lb.book_id
    HAVING current_borrowers = total_copies
) as tab
ORDER BY tab.current_borrowers DESC, tab.title ASC
