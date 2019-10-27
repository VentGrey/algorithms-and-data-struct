# Esta la función que encuentra la respuesta a cada caso

def get_min_dist(locations, cows):
    locations.sort()
    n = len(locations)
    lo = locations[1] - locations[0] # Distancia minima entre casetas
    hi = locations[n - 1] - locations[0] # Distancia maxima entre casetas

    while lo + 1 < hi:
        x = lo + (hi - lo) // 2
        alloc_cows = 1
        current_loc = locations[0]

        for i in range(1, len(locations)):
            if locations[i] - current_loc >= x:
                # Puedo poner vaca
                alloc_cows += 1
                current_loc = locations[i]

        if alloc_cows >= cows:
            lo = x
        else:
            hi = x - 1

    return hi

# Prueba con el ejemplo de la página

a = [1, 2, 8, 4, 9]
print(get_min_dist(a, 3))

