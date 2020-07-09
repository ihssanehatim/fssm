import os
import sys

stderr = sys.stderr
sys.stderr = open(os.devnull, 'w')
from textgenrnn import textgenrnn
sys.stderr = stderr

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
textgen = textgenrnn(weights_path='bio_weights.hdf5', vocab_path='bio_vocab.json', config_path='bio_config.json')
stdout = sys.stdout
textgen.generate()
