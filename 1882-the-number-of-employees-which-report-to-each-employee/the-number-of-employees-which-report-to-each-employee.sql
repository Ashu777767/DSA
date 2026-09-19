SELECT 
    E.employee_id,
    E.name,
    COUNT(t.employee_id) AS reports_count,
    ROUND(AVG(t.age)) AS average_age
FROM Employees AS E
JOIN Employees AS t
    ON E.employee_id = t.reports_to
GROUP BY E.employee_id, E.name
ORDER BY E.employee_id;