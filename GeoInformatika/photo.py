import numpy as np
from scipy.signal import hilbert
from scipy.io import wavfile
import matplotlib.pyplot as plt

file_path = "signal.WAV"
sr, signal = wavfile.read(file_path)


analytic_signal = hilbert(signal)
amplitude_envelope = np.abs(analytic_signal)

from PIL import Image

width = 5512
height = len(amplitude_envelope) // width + 1
padded_amplitude_envelope = np.pad(amplitude_envelope, (0, width - len(amplitude_envelope) % width), mode='constant')
image_matrix = padded_amplitude_envelope.reshape(height, width)

image = Image.fromarray(image_matrix)
plt.figure(figsize=(10, 5))
plt.imshow(image, cmap='gray')
plt.axis('off')
plt.title('Изображение огибающей амплитуды')
plt.show()