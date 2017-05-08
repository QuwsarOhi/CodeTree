import numpy as np

class Perceptron(object):
	'''Perceptron classifier.
	
	Parameters
	--------------
	eta : float
			Learning rate (between 0.0 and 1.0)
	n_iter: int
			Passes (fit, no. of epoch) over training dataset
			
	Attributes
	--------------
	w_ : 1d-array
		Weights after fitting
	errors_ : list
		Numer of miscalculations in every epoch
	'''
	def __init__ (self, eta = 0.01, n_iter = 10):
		self.eta = eta
		self.n_iter = n_iter
		
	def fit(self, X, y):
		
		'''Fit training data
		
		Parameters
		-------------
		X : {array-like}, shape(row, column) = [n_samples, n_features]
		Training vectors, where n_samples is the number of samples and
		n_features is the number of features.

		y : array-like, shape(row) = [n_samples]
		Target values (the right answers).
		
		Returns
		----------
		self : object
		'''
		
		# Creating 0 weight numpy array length of (feature + 1)
		self.w_ = np.zeros(1 + X.shape[1])
		self.errors_ = []
		'''
		w(j) : = w(j) + ∆w(j)		j = j'th feature, w = weight
		
		∆wj = η * (y(i) − yˆ(i)) * x(i)(j)
		Here, 
			y(i) = target output for i'th sample [true class label]
			y^(i) = calculated output for u'th sample [predicted class label]
			x(i)(j) = value of j'th feature of i'th sample
			
		y^(i) = w0x0 + w1x1 + ... + w(j)x(j)  	[dot product of w and x(i)]	
		'''
		
		for _ in range(self.n_iter):
			errors = 0
			for xi, target in zip(X, y):
				
				# xi is the array of fatures of i'th sample
				# predict(xi) = y^(i), which generates the class label, (1 or -1)
				update = self.eta * (target - self.predict(xi))
				
				# del_w = ∆w(1), ∆w(2), ∆w(3), ..... , ∆w(j)	note that ∆w(0) is missing
				del_w = update * xi
				
				# These two lines updates the weights 
				self.w_[1:] += del_w
				self.w_[0] = update
				
				errors += int(update != 0.0)
			self.errors_.append(errors)
			
		return self
	
	def	net_input(self, X):
		'''Calculate the net input
		X = x1, x2, x3, .... xn
		w_ = w0, w1, w2, w3, .... wn
		
		x0 is in X, which is not given
		x0 = 1
		so, w[0] * x[0] = w[0]
		'''
		return np.dot(X, self.w_[1:]) + self.w_[0]
		
	def predict(self, X):
		'''Return class label after unit step'''
		return np.where(self.net_input(X) >= 0.0, 1, -1)


from matplotlib.colors import ListedColormap

def plot_decision_regions(X, y, classifier, resolution=0.02):
	
	# setup marker generator and color map
	markers = ('s', 'x', 'o', '^', 'v')
	colors = ('red', 'blue', 'lightgreen', 'gray', 'cyan')
	cmap = ListedColormap(colors[:len(np.unique(y))])
	
	# plot the decision surface
	x1_min, x1_max = X[:, 0].min() - 1, X[:, 0].max() + 1
	x2_min, x2_max = X[:, 1].min() - 1, X[:, 1].max() + 1
	xx1, xx2 = np.meshgrid(np.arange(x1_min, x1_max, resolution), np.arange(x2_min, x2_max, resolution))
	Z = classifier.predict(np.array([xx1.ravel(), xx2.ravel()]).T)
	Z = Z.reshape(xx1.shape)
	plt.contourf(xx1, xx2, Z, alpha=0.4, cmap=cmap)
	plt.xlim(xx1.min(), xx1.max())
	plt.ylim(xx2.min(), xx2.max())
	
	# plot class samples
	for idx, cl in enumerate(np.unique(y)):
		plt.scatter(x=X[y == cl, 0], y=X[y == cl, 1], alpha=0.8, c=cmap(idx), marker=markers[idx], label=cl)


if __name__ == '__main__':
	import pandas as pd
	import matplotlib.pyplot as plt
	
	# Building dataframe
	df = pd.read_csv('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data', header=None)
	
	# To show the data frame uncomment this line
	# df.tail()
	
	# The labels are on the 4'th column [Zero based index]
	y = df.iloc[0:100, 4].values
	
	# Change 'Iris-setosa' to 1, else to -1
	y = np.where(y == 'Iris-setosa', -1, 1)
	
	# Taking 100 test elements and only using 0th and 2nd feature
	X = df.iloc[0:100, [0, 2]].values
	
	# Scatter points in graph
	plt.scatter(X[:50, 0], X[:50, 1], color='red', marker='o', label='setosa')
	plt.scatter(X[50:100, 0], X[50:100, 1], color='blue', marker='x', label='versicolor')
	
	# Label the axises
	plt.xlabel('sepal length')
	plt.ylabel('petal length')
	plt.legend(loc = 'upper left')
	plt.savefig('iris_plot.png')
	
	# Feeding Perceptron with data
	ppn = Perceptron(eta=0.1, n_iter=10)
	ppn.fit(X, y)
	
	# Plotting errors in graph
	plt.plot(range(1, len(ppn.errors_)+1), ppn.errors_, marker='o')
	plt.xlabel('Epochs')
	plt.ylabel('Number of misclassifications')
	plt.savefig('epoch.png')
	# plt.show()
	
	plot_decision_regions(X, y, classifier=ppn)
	plt.xlabel('sepal length')
	plt.ylabel('petal length')
	plt.savefig('predicted_classification.png')
	plt.show()
