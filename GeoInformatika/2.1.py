import wave
import numpy as np
import matplotlib.pyplot as plt

# Открываем wav-файл для чтения
wav_file = wave.open('signal.WAV', 'rb')

sample_rate = wav_file.getframerate()
print(f'Частота дискретизации: {sample_rate} Гц')

num_frames = wav_file.getnframes()
audio_data = wav_file.readframes(num_frames)
wav_file.close()

audio_data1 = np.array(audio_data)


plt.plot(audio_data1)
plt.xlabel('Время, с')
plt.xlim(0, 2)  # Ограничиваем график двумя секундами
plt.show()