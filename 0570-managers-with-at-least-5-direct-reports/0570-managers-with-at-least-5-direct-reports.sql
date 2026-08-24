# Write your MySQL query statement below
select e2.name
from Employee as e1
inner join Employee as e2
on e1.managerId=e2.id
group by
e1.managerID,
e2.name
having
count(e1.managerID)>=5;