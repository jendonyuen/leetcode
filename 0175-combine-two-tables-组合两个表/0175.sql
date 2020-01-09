# Write your MySQL query statement below
select FirstName, LastName, City, State from Person a left join Address p on a.PersonId=p.PersonId;