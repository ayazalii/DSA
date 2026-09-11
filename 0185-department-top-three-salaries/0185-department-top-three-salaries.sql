# Write your MySQL query statement below
with new_table as
(
    select
    d.name as department,
    e.name as employee,
    e.salary as salary,
    dense_rank() over (
        partition by d.name
        order by e.salary desc
    )
    as ranking
    from employee e
    left join department d
    on e.departmentId=d.id
)
select department,
employee,salary
from new_table
where ranking<=3