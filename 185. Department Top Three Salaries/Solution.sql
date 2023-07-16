# Write your MySQL query statement below
SELECT dep.name AS Department,emp.name AS Employee, emp.salary AS Salary FROM (
SELECT  *,DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS r
FROM Employee 
) AS emp
JOIN Department AS  dep
ON dep.id=emp.departmentId
WHERE r<=3;