from scipy.io.wavfile import *
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import hilbert, resample
from scipy.io import wavfile

file_path = "signal.WAV"
sr, signal = wavfile.read(file_path)


analytic_signal = hilbert(signal)

rate = 2080 * 2
k = 3
#если делать k = 2.56, то будет получаться ошибка "slice indices must be integers or None or have an index method"

sample_rate = 11025

resampled = resample(analytic_signal, int(analytic_signal.shape[0] * rate * k / sample_rate))
resampled = np.array(resampled, dtype=complex)

normalized = ((resampled - min(resampled)) / ((max(resampled) - min(resampled)) / 2)) - 1
amplitude_envelope = np.abs(normalized)

strings_2 = []
for i in range(0, len(amplitude_envelope), int(rate * k / 2)):
    string_2 = amplitude_envelope[i:i + int(rate * k / 2):k]
    strings_2.append(string_2)


plt.figure()
plt.imshow(strings_2[:-1], cmap='gray')
plt.title('Resampled Image (plot only every k-th pixel)')
plt.show()