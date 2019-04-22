import csv
ifile  = open('air_quality_Nov2017.csv', "rt", encoding='UTF8')
print("Press 1 to search by Station \n" +
      "Press 2 to search by Air Quality \n"+
      "Press 3 to search by O3 Value \n"+
      "Press 4 to search by NO2 Value \n"+
      "Press 5 to search by PM10 Value \n")

#Determine the users choice
n = int(input("Enter your choice: "))

# Search details by Station
if(n == 1):
    key = input('Enter Station:') 
    if(len(key) > 0):
        read = csv.reader(ifile)
        for row in read :
            if(key in row[0]):
                 print(row)
    else:
        print("The data doesn't exist")

# Search details by Air Quality
elif(n == 2):
    key = input('Enter Air Quality:') 
    if(len(key) > 0):
        read = csv.reader(ifile)
        for row in read :
            if(key in row[1]):
                 print(row)
    else:
        print("The data doesn't exist")


# Search details by O3 Value 
elif(n == 3):
    key = input('Enter O3 Value:') 
    if(len(key) > 0):
        read = csv.reader(ifile)
        for row in read :
            if(key in row[6]):
                 print(row)
                
    else:
        print("The data doesn't exist")

# Search details by NO2 Value
elif(n == 4):
    key = input('Enter NO2 Value:') 
    if(len(key) > 0):
        read = csv.reader(ifile)
        for row in read :
            if(key in row[9]):
                 print(row)
                
    else:
        print("The data doesn't exist")

# Search details by PM10 Value
elif(n == 5):
    key = input('Enter PM10 Value:') 
    if(len(key) > 0):
        read = csv.reader(ifile)
        for row in read :
            if(key in row[12]):
                 print(row)
                
    else:
        print("The data doesn't exist")

else:
    print("Enter a valid number for your choice.")
