from datetime import date

def isLeapYear(year):
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

def daysInMonth(month, year):
    if (month < 8 and month % 2 == 1) or (month > 7 and month % 2 == 0):
        return 31
    if month == 2:
        return 29 if isLeapYear(year) else 28
    return 30

def daysBetweenDates(m1, d1, y1, m2, d2, y2):
    sum = 0
    sum += daysInMonth(m1, y1) - d1
    sum += d2
    for year in range(y1+1, y2):
        sum += 366 if isLeapYear(year) else 365
    if y1 == y2:
        for month in range(m1+1, m2):
            sum += daysInMonth(month, y1)
    else:
        for month in range(m1+1, 13):
            sum += daysInMonth(month, y1)
        for month in range(1, m2):
            sum += daysInMonth(month, y2)
    return sum 


def daysBetweenDates2(m1, d1, y1, m2, d2, y2):
    d0 = date(y1, m1, d1)
    d1 = date(y2,m2,d2)
    delta = d1 - d0
    return delta.days


print(daysBetweenDates(6,19,2019, 11,8,2020))
print(daysBetweenDates2(6,19,2019, 11,8,2020))
print()
print(daysBetweenDates(1, 1, 1900, 6,19,2019))
print(daysBetweenDates2(1, 1, 1900, 6,19,2019))
print()
print(daysBetweenDates(1, 1, 1800, 9,11,2001))
print(daysBetweenDates2(1, 1, 1800, 9,11,2001))
print()
print(daysBetweenDates(11,23, 1973, 6,19,2019))
print(daysBetweenDates2(11,23, 1973, 6,19,2019))
print(daysBetweenDates2(12,29, 2002, 6,19,2019))