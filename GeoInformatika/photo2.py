from scipy.io.wavfile import read
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import hilbert, resample

rate = 2080 * 2

input_data = read('signal.wav')
audio = np.array(input_data[1], dtype=float)
normalized = ((audio - np.min(audio)) / ((np.max(audio) - np.min(audio))/2)) - 1
analytic_signal = hilbert(normalized)
amplitude_envelope = np.abs(analytic_signal)
resampled = resample(amplitude_envelope, int(amplitude_envelope.shape[0] * rate/ 11025))
resampled = ((resampled - min(resampled)) / (max(resampled) - min(resampled)))

sync = np.array([0] * 4 + [1, 1, 0, 0] * 7 + [0] * 7, dtype=float)
range_between = 2000;
peaks = [(0, 0)]
shifted_signal = resampled - 0.5
sync -= 0.5
img = []

for i in range(len(resampled) - len(sync)):
    edge = np.dot(sync, shifted_signal[i:i + len(sync)])
    if i - peaks[-1][0] >= rate / 2:
        peaks.append((i, edge))
    elif edge > peaks[-1][1]:
        peaks[-1] = (i, edge)

for i in range(len(peaks) - 1):
    img.append(resampled[peaks[i][0]:peaks[i][0] + 2080])

from PIL import Image

pixvals = img

minval = np.percentile(pixvals, 0)
maxval = np.percentile(pixvals, 100)
pixvals = np.clip(pixvals, minval, maxval)
pixvals = ((pixvals - minval) / (maxval - minval)) * 255
img = Image.fromarray(pixvals.astype(np.uint8))
img_copy = np.copy(img)

plt.figure(figsize = (10, 14))
plt.imshow(img, cmap='gray')
plt.show()