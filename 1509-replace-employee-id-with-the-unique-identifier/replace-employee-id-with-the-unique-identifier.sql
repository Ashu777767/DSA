# Write your MySQL query statement below
SELECT u.unique_id ,name FROM Employees as e
LEFT JOIN  EmployeeUNI as u
ON e.id = u.id;