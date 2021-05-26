import tensorflow as tf
import numpy as np

# 2-D tensor 'p'
# [[0.51],
#  [0.59],
#  [-0.15]]

p = tf.constant([0.51, 0.59, -0.15], shape=[3, 1])

### 2-D tensor 'W'
### [[ 0.57, 0.57,-0.79,  0.75]]

W = tf.constant([0.57, -0.79, 0.75], shape=[1, 3])

### 2-D tensor 'b'
## [[0.8]]

b = tf.constant([0.8], shape=[1, 1])
     
n = tf.matmul(W, p)+b # n = Wp+ b

print(f"Salida n: {n}")

a = tf.keras.activations.tanh(n).numpy()

print(f"Salida a: {a}")


