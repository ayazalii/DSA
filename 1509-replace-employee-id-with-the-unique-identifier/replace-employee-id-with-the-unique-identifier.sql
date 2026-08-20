# Write your MySQL query statement below
select employeeuni.unique_id, employees.name
from Employees
left join employeeuni on Employees.id = employeeuni.id;