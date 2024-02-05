# programs-for-recording-the-seniority-of-the-company-s-employees
 C ++, OOP software

# The program provide for:
- handling of exceptional situations:
- the data entered by the user does not match the field format (for example,
characters in a numeric field);
- the data entered by the user is incorrect (for example, a negative price of an item);
- the file with the data does not exist;
- nothing was found for the search data entered;
- the number of the record to be deleted is outside the array/vector;
- the login for the new account already exists;
- the ability to go back (navigation);
- a request to perform irreversible processes, namely, confirmation of deletion,
for "Do you really want to delete the file (record)?";
- user feedback, for example, displaying a message about
success of file creation/deletion of a record/etc.

# Development of a program for accounting for the length of service of employees of the enterprise
Information about the company's employees includes: FULL NAME
name of the employee; date of birth; name of the department; position; date of start of work.
Individual task: print the list of employees of retirement age in
in descending order of seniority.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# The administrator module includes the following submodules (with an indication of functionality):
1. Working with user accounts:
- viewing all accounts;
- adding a new account;
- edit an account;
- delete an account.
2. Working with a data file:
- reading data from a file;
- writing data to a file;
- writing data to an existing file at the end;
- deleting the file.
3. Working with data:
a) edit mode:
- viewing all data;
- adding a new record;
- deleting a record;
- edit a record;
b) data processing mode:
- performing an individual task;
- data search (by at least three different parameters);
- sorting (by at least three different parameters).

![image1](https://github.com/Taras-P-Kob/programs-for-recording-the-seniority-of-the-company-s-employees/assets/119957094/73c0dec7-7dea-445c-99a9-115a59438775)

Picture 1. Administrator menu

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# The user module includes a submodule for working with data with the following functionalities:
- viewing all data;
- performing an individual task;
- data search (by at least three different parameters);
- sorting (by at least three different parameters).

![image2](https://github.com/Taras-P-Kob/programs-for-recording-the-seniority-of-the-company-s-employees/assets/119957094/dfa10819-82f6-449f-9e77-2b873a5d496f)

Picture 2. User menu

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

4. Description of the program operation
4.1 Authorization (1,2  Picture)

This code checks the login and password entered by the user, comparing them with the values read from the file "data.txt". If the entered data matches the values from the file, the authorization is considered successful.
If d=1 Log in as administrator.
If d=2 Log in as a user.


4.2. The administrator module.
The administrator module (Pic. 3) in this code includes a set of operations that can be performed by users with the "administrator" access level. The main part of this module is contained in the MenuAdmin() function. The main operations that can be performed in this module include: 
Displaying employees: Reading employee data from the "employees.txt" file and displaying it.

Viewing data: Reading data from the "data.txt" file and displaying it.

Editing data: Edit the "employees.txt" and "data.txt" files by adding new data or deleting existing data.

Sorting employees: Sort employees by various criteria such as date of birth, department, name, etc.

Search for employees: Search for employees by various criteria such as date of birth, department, name, etc. 

 In the administrator menu, select the option to view information about employees (Display) 

![image4](https://github.com/Taras-P-Kob/programs-for-recording-the-seniority-of-the-company-s-employees/assets/119957094/25aa66b7-0bb6-4f88-b695-cba7a040e832)

3 Picture. Example of adding a new user 

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4.3. The user module. 

The user module (Pic. 4,5) in this code provides opportunities for users with the "user" access level. This module implements the MenuUser() function, which contains the basic operations available to users with this access level. The basic operations include:
 
Displaying employees: Reading data about employees from the "employees.txt" file and displaying it.
 
 Sorting employees: Sort employees by various criteria such as date of birth, department, name, etc.

 Search for employees: Search for employees by various criteria such as date of birth, department, name, etc.
 The user can view the list of employees and select a sort or search criterion by which the data will be sorted or found.
 


![image10](https://github.com/Taras-P-Kob/programs-for-recording-the-seniority-of-the-company-s-employees/assets/119957094/85e93ef8-c3b3-460e-99fa-bdbaa24537e0)

4 Picture. The user has selected the Search option in the menu by start date

![image3](https://github.com/Taras-P-Kob/programs-for-recording-the-seniority-of-the-company-s-employees/assets/119957094/706c2843-d4eb-4404-9cfa-8c709c4ade51)

5 Picture. Example of sorting (by position)

