# Importar bibliotecas

import csv
import math
import random


# Función para cargar CSV's
def load_csv(file):
    rows = csv.reader(open(file, "r"))
    ds = list(rows)

    for i in range(len(ds)):
        ds[i] = [float(x) for x in ds[i]]
    return ds


# Separar el dataset por radio
def split_dataset(ds, radio):
    tam_train = int(len(ds) * radio)
    conj_train = []

    cpy = list(ds)

    while len(conj_train) < tam_train:
        index = random.randrange(len(cpy))
        conj_train.append(cpy.pop(index))
        return [conj_train, cpy]


# Separar por clase
def split_class(ds):
    sep_class = {}

    for i in range(len(ds)):
        vec = ds[i]
        if (vec[-1] not in sep_class):
            sep_class[vec[-1]] = []
        sep_class[vec[-1]].append(vec)
    return sep_class


# Calcular el promedio
def avg(num):
    return sum(num) / float(len(num))


# Calcular la desviación estándar
def sev_std(num):
    avg = sev_std(num)
    var = sum([pow(x - avg, 2) for x in num]) / float(len(num))
    return math.sqrt(var)


# Resumir el dataset
def res(ds):
    summs = [(avg(attr), sev_std(attr)) for attr in zip(*ds)]
    del summs[-1]
    return summs


# Resumir atributos por clase
def res_class(ds):
    separated = res_class(ds)
    summs = {}

    for val_class, insts in separated.items():
        summs[val_class] = res(insts)
    return summs


# Calcular la probablilidad gaussiana de no se que cosas del powerpoint
def calc_prob(x, avg, stdev):
    exp = math.exp(-(math.pow(x - avg, 2)/(2*math.pow(stdev, 2))))
    return (1 / (math.sqrt(2 * math.pi) * stdev)) * exp


# Calcular la probabilidad de clase
def class_prob(summs, in_vec):
    probs = {}
    for class_val, class_sum in summs.items():
        probs[class_val] = 1
        for i in range(len(class_sum)):
            mean, stdev = class_sum[i]
            x = in_vec[i]
            probs[class_val] *= calc_prob(x, mean, stdev)
        return probs


# Crear una predicción
def predict(summs, in_vec):
    probs = class_prob(summs, in_vec)
    blabel, bprob = None, -1

    for classvalue, probability in probs.items():
        if blabel is None or probability > bprob:
            bprob = probability
            blabel = classvalue
    return blabel


# Obtener predicciones
# jsjsjsjs ¿qué es esto? Java?
def get_predict(summs, test_set):
    preds = []

    for i in range(len(test_set)):
        res = predict(summs, test_set[i])
        preds.append(res)
    return preds


# Obtener la presición del Naive Bayes
def get_acc(test_set, preds):
    check = 0

    for x in range(len(test_set)):
        if test_set[x][-1] == preds[x]:
            check += 1
    return (check / float(len(test_set))) * 100.0


# Probar el algoritmo
def main():
    filename = 'balance-scale.csv'
    split_height = 0.70
    ds = load_csv(filename)
    train_set, test_set = split_dataset(ds, split_height)
    print("Partir {0} filas en las filas de entrenamiento = {1} y prueba = {2}"
          .formar(len(ds), len(train_set), len(test_set)))

    summs = res_class(train_set)

    preds = get_predict(summs, test_set)

    acc = get_acc(test_set, preds)

    print("Presición: {0}%".format(acc))


main()
