from math import radians, sin, cos, sqrt, atan2

def haversine_distance(lat1, long1, lat2, long2):
    r = 6371
    d_lat = radians(lat2 - lat1)
    d_long = radians(long2 - long1)
    a = sin(d_lat / 2)**2 + cos(radians(lat1)) * cos(radians(lat2)) * sin(d_long / 2)**2
    c = 2 * atan2(sqrt(a), sqrt(1 - a))
    d = r * c
    return d

if __name__ == '__main__':
    lat1 = float(input("Enter latitude 1: "))
    long1 = float(input("Enter longitude 1: "))
    lat2 = float(input("Enter latitude 2: "))
    long2 = float(input("Enter longitude 2: "))

    distance = haversine_distance(lat1, long1, lat2, long2)
    print("The points ({}, {}) and ({}, {}) are {} km apart.".format(lat1, long1, lat2, long2, distance))