import matplotlib.pyplot as plt
from keras.utils import to_categorical
from keras.models import Sequential
from keras.layers import Dense, Conv2D, Flatten
import numpy as np
from keras.datasets import mnist

def build_model(in_shape):
    model = Sequential()
    model.add(Conv2D(2, kernel_size=2, activation='relu', input_shape=in_shape, padding='same'))
    model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
    return model

'''
(X_train, y_train), (X_test, y_test) = mnist.load_data()
X_train = X_train.reshape(60000,28,28,1)
X_test = X_test.reshape(10000,28,28,1)
y_train = to_categorical(y_train)
y_test = to_categorical(y_test)


print(X_train.shape[1:])
x = input()
y = input()
model = build_model(X_train.shape[1:])
model.fit(X_train, y_train, validation_data=(X_test, y_test), epochs=3)
'''


x = np.random.rand(3, 4, 4)
y = np.array([0, 1, 2])

x = x.reshape(x.shape[0], x.shape[1], x.shape[2], 1)
y = to_categorical(y)

print(x.shape, y.shape)


model = build_model(x.shape[1:])
model.fit(x, y, epochs=1)
print('DONE')
