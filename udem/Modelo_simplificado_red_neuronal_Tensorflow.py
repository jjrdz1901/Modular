import tensorflow as tf

p = tf.constant([0.51, 0.59, -0.15], shape=[3, 1])


W = tf.constant([0.57, -0.79, 0.75], shape=[1, 3])


b = tf.constant([0.8], shape=[1, 1])
     
n = tf.matmul(W, p)+b # n = Wp+ b

print(f"Salida n: {n}")
