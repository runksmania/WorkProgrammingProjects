from employee import Employee

employees = {}

with open('employees.txt', 'r') as f:
  temp_employee = None

  for line in f:
    line = line[:-1]
    line_split = line.split(':')

    if line_split[0] == 'name':
      first_name, last_name = [i for i in line_split[1].split()]
      temp_employee = Employee(first_name, last_name)
