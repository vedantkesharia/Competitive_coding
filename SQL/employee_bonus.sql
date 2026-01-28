SELECT Employee.name, Bonus.bonus
FROM Employee
LEFT JOIN Bonus ON Bonus.empId = Employee.empId
WHERE bonus is NULL OR bonus<1000