from datetime import datetime
import psycopg2
#database interaction code written by Panatda Wiagngoen, edits/bug fixes by Johnathan Gonzalez

#establishing the connection
conn = psycopg2.connect(database="postgres", user='postgres',password ='postgres', host='localhost', port=5432 )

#Creating a cur object using the cur() method
cur =conn.cursor()

#Executing an SQL function using the execute() method
cur.execute("select version()")

# Fetch a single row using fetchone() method.
data =cur.fetchone()
print("Connection established to: ", data)

'''def fetch(id):
    cur.execute("SELECT * FROM Employees WHERE empID=(%s::bigint)", (id,))
    row = cur.fetchone
    return row'''

def insert(id, fname, lname, email, phone):
    #grab data and insert
    """query = ''' INSERT INTO Employees(empID, Fname, Lname, email, phone) 
                  values (%s, %s, %s, %s, %s)'''
    id = input("Employee ID: ")
      fname = input("First Name: ")
      lname = input("Last name: ")
      email = input("Email address: ")
      phone = input("Phone number: ")
      #record = (938645028788, 'Panatda', 'Wiangngoen', 'panatda@usf.edu', 8137703159)
      record = (id, fname, lname, email, phone)
      cur.execute(query, record)"""
    query = """INSERT INTO Employees(empID, Fname, Lname, email, phone) 
                  values (%s, %s, %s, %s, %s)"""
    record = (id, fname, lname, email, phone)
    cur.execute(query, record)
    conn.commit()
   
def delete(id):
    #remove employee
    cur.execute("""DELETE FROM Employees WHERE empID=%s""", (id,))
    conn.commit()

def update(id, credit):
    cur.execute("UPDATE Employees SET credit=%s WHERE empID=%s", (credit, id))
    conn.commit()

#search database for employee or admin ID
def search(x):
    cur.execute("SELECT "+str(x) +" FROM Employees")
    Ename = cur.fetchall()
    Aname=cur.execute("SELECT adminID FROM Administrators ")
    Aname = cur.fetchall()
    return Ename, Aname #returns everything, but must use 'for name in search:'

def record(id,brtrn):
    query = """INSERT INTO Scanner(scanID, logWhen, retrn) values(%s, %s,%s)"""
    dt = datetime.now()
    record = (id,dt,brtrn)
    cur.execute(query,record)
    conn.commit()

def get_credit(id):
    cur.execute("SELECT credit FROM Employees")
    credit = cur.fetchone()
    return credit[0]

def trig_credit(num):
    cur.execute("UPDATE Employees Set credit=%s ", (num))
    conn.commit()

def all_records():
    cur.execute("SELECT S.logWhen, S.retrn, E.fname, E.lname, E.credit, E.email, E.phone FROM Employees E JOIN Scanner S ON(E.empID=S.scanID)")
    row=cur.fetchone()
    return row

def no_returns():
    cur.execute("SELECT S.logWhen, s.retrn, E.fname, E.lname, E.credit, E.email, E.phone FROM Employees E JOIN Scanner S On(E.empID = S.scanID AND S.retrn = 0)")
    row = cur.fetchone()
    return row

def close():
    conn.close()



'''class Databse:
   #establishing the connection
   def _init_(self, db):
      self.conn = psycopg2.connect(
      database="Information", user='postgres', password='postgres', 
      host='127.0.0.1', port= '5432')
      #Creating a cur object using the cur() method
      self.cur = self.conn.cursor()
      #Executing an SQL function using the execute() method
      self.cur.execute("select version()")
      # Fetch a single row using fetchone() method.
      data = self.cur.fetchone()
      print("Connection established to: ", data)
   def fetch(self, id):
      self.cur.execute("SELETE * FROM Employees WHERE id=%s", (id,))
      row = self.cur.fetchall()
      return row
      
   def insert(self, id, fname, lname, email, phone):
      #grab data and insert
      """query = "INSERT INTO Employees(empID, Fname, Lname, email, phone) 
                  values (%s, %s, %s, %s, %s)"
      id = input("Employee ID: ")
      fname = input("First Name: ")
      lname = input("Last name: ")
      email = input("Email address: ")
      phone = input("Phone number: ")
      #record = (938645028788, 'Panatda', 'Wiangngoen', 'panatda@usf.edu', 8137703159)
      record = (id, fname, lname, email, phone)
      cur.execute(query, record)"""
      query = """INSERT INTO Employees(empID, Fname, Lname, email, phone) 
                  values (%s, %s, %s, %s, %s))"""
      record = (id, fname, lname, email, phone)
      self.cur.execute(query, record)
      self.conn.commit()
   
   def delete(self, id):
      #remove employee
      self.cur.execute("DELETE FROM Employees WHERE id=?", (id,))
      self.conn.commit()
   def update(self, id, credit):
      self.cur.execute("UPDATE Employees SET credit=? WHERE id=?", (credit, id))
      self.conn.commit()
   def _del_(self):
      self.conn.close()'''
