from scipy.io.wavfile import read
import matplotlib.pyplot as plt

# read audio samples
input_data = read("signal.WAV")
audio = input_data[1]
print(len(input_data[1]))
plt.plot(audio[0:30000])
plt.plot()
plt.show()