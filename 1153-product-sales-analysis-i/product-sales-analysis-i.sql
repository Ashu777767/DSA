# Write your MySQL query statement below
SELECT pd.product_name,year,price FROM Sales as s
LEFT JOIN Product as pd
ON s.product_id = pd.product_id;
