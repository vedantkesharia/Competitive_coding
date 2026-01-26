SELECT Person.lastName, Person.firstName, Address.city, Address.state
FROM Person
LEFT JOIN Address On Person.personId = Address.personId;