import tensorflow as tf
import numpy as np

# 2-D tensor 'n'
# [[1],
#  [3],
#  [2.5]]

n = tf.constant([1, 3, 2.5], shape=[1, 3])

print(f"Salida n: {n}")

a = tf.keras.activations.softmax(n).numpy()

print(f"Salida a: {a}")


