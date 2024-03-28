import soundfile as sf
import matplotlib.pyplot as plt

# Загрузка аудиофайла
audio_path = 'signal.WAV'
data, samplerate = sf.read(audio_path)

# Построение графика
plt.figure(figsize=(15, 5))
plt.plot(data)
plt.title('Звуковой сигнал')
plt.xlim(0, 30000)
plt.show()
import numpy as np
from scipy.signal import hilbert

cropped_data = data[1000:2000]

# Compute the Hilbert transform to get the analytic signal
analytic_signal = hilbert(cropped_data)
amplitude_envelope = np.abs(analytic_signal)

# Plot the original signal and the Hilbert envelope
plt.figure(figsize=(15, 5))
plt.plot(cropped_data, label='Original Signal')
plt.plot(amplitude_envelope, label='Hilbert Envelope', color='orange')
plt.title('Звуковой сигнал и гильбердова кривая')
plt.legend()
plt.show()