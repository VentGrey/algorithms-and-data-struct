using DataFrames, CSV, DataStructures, Random, Pkg


struct KNN
    x::DataFrames.DataFrame
    y::DataFrames.DataFrame
end


#=
Explicación de las bibliotecas:
- DataFrames: Biblioteca de Julia para manejar y manipular datos
  tabulares en julia como Bases de datos, CSV o archivos excel.
- CSV: Biblioteca de Julia para manejar y manipular CSV
- DataStructures: Colección de estructuras de datos comunes como:
# Linked list
# Binary Heap
# Stack
# Árbol AVL
# etc
- Random: Pos su nombre lo dice
- Pkg: Para usar imports de forma sabia
=#

# Función para calcular distancia de dos puntos A -> B
# Argumentos:
# src_pt: Punto de origen (A)
# ds_pt: Punto de destino (B)
function calc_dist(src_pt, ds_pt)
    # return sqrt(sum((ds_pt .- src_pt) .^ 2))
    sum = 0.0

    for i in 1:length(src_pt)
        sum += (ds_pt[i] - src_pt[i]) ^ 2
    end

    dist = sqrt(sum)
    return dist
end

# Función "popularity contest" para sacar las frecuencias y etiquetas
function pop_con(targets)
    pop_freq = counter(targets)

    nVal = 0
    nKey = "BLR" # Nomas para rellenar

    for key in keys(pop_freq)
        if pop_freq[key] > nVal
            nKey = key
            nVal = pop_freq[key]
        end
    end
    # Descomentar para depurar funcíon
    # println("Norm Key:", nkey)
    return nKey
end

# Función para partir el DataSet el punto decimal indica a que altura se desea
# partir el dataset, en este caso a la mitad porque pos xdXdXDxDxDXD
function split_dataset(data, at = 0.5)
    n = nrow(data)
    ind = shuffle(1:n) # Indice
    train_ind = view(ind, 1:floor(Int, at*n))
    test_ind = view(ind, (floor(Int, at*n)+1):n)
    return data[train_ind,:],data[test_ind,:]
end

# Función super hacker parap redecir cositas con el KNN
# Normalmente me acordaría de hacer la función para el "training"
# PERO por ahí me pasaron el chisme de que con una función predict
#
#En esta función las distancias entre dos puntos objetivos y los "puntos" de
#entrenamiento son calculados por la llave/etiqueta del punto "K" más cercano
# podemos decidir cuantos "K" queremos. Esta función va a ordenar los datos
# y va a regresar los índices de los datos ordenados
function predict(data::KNN, testData::DataFrames.DataFrame, k=5)
    predictedLabels = []
    for i in 1:size(testData, 1)
        sourcePoint = Array(testData[i,:])
        distances = []
        for j in 1:size(data.x, 1)
            destPoint = Array(data.x[j,:])
            distance = calc_dist(sourcePoint, destPoint)
            push!(distances, distance)
        end
        sortedIndex = sortperm(distances)
        targetCandidates = Array(data.y)[sortedIndex[1:k]]
        predictedLabel = pop_con(targetCandidates)
        push!(predictedLabels, predictedLabel)
    end
    return predictedLabels
end

# Ora si lo chido
function main()
    # Leer el dataset
    df = DataFrame(CSV.File("balance-scale.csv"))

    # Descomentar para mostrar el CSV cargado
    # df

    # Mochar los datos a la mitad para "Entrenamiento" y "Prueba"
    train, test = split_dataset(df)

    xtrain = train[:, [:leftWeight, :leftDistance, :rightWeight, :rightDistance]]
    ytrain = train[:, [:ClassName]]

    xtest = test[:, [:leftWeight, :leftDistance, :rightWeight, :rightDistance]]
    ytest = test[:, [:ClassName]]
    
    knn = KNN(xtrain, ytrain)
    pred = predict(knn, xtest)

    # Evaluar
    correctos = 0

    y_testarr = Array(ytest)

    for i in 1:length(pred)
        if y_testarr[i] == pred[i]
            correctos += 1
            # Descomentar para Depurar
            # println("Correctos: ", correctos)
        end
    end
    println("Presición: ", correctos / length(pred))
end

main()
