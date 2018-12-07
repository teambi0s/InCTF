### Chall Name
s3cur3 carz

### Chall Description
This website is a very s3cur3 car info dispenser and by far the most safest one avaliable. It shows literally no 'Defect's.

### Chall Link
13.233.155.110

### Chall Flag
inctf{this_is_what_it_means_to_solve_a_simple_challenge}

### Chall Solution
There is a SQL Injection with 'Alias' in the table field.
A post request was to be sent with: id=5&option=(select 5 ID, Defect CarName from fiat) fiat&submit=Submit
Then the Car Name output field gives the output: /r12DCMji12hUHD7yGda
On going to that directory we find the flag commented out in the "view source".

### Chall Author
[c3rb3ru5](https://twitter.com/__c3rb3ru5__)

