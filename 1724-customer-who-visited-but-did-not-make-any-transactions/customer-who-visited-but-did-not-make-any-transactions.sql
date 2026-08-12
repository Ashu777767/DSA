# Write your MySQL query statement below
SELECT customer_id,COUNT(visit_id) as count_no_trans FROM Visits as v
LEFT JOIN Transactions as t
USING(visit_id) 
WHERE t.visit_id IS NULL
GROUP BY customer_id;