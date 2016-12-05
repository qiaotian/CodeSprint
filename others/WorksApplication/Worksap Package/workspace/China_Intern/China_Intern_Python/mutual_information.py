# @Author: Tian Qiao <qiaotian>
# @Date:   2016-11-27T11:32:01+08:00
# @Email:  qiaotian@me.com
# @Last modified by:   qiaotian
# @Last modified time: 2016-11-27T11:32:01+08:00


import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2
from minepy import MINE
from scipy.stats import pearsonr
from sklearn.cross_validation import train_test_split
from sklearn.cross_validation import cross_val_score

feature_cols = []
with open('genotype.csv') as f:
    firstline = f.readline()
    feature_cols = np.array(firstline.split(','))

genotype_df         = pd.read_csv('./data/genotype.csv', header=0, names=feature_cols)
pheno_df            = pd.read_csv('./data/phenotype.txt', header=None)
multi_phenos_df     = pd.read_csv('./data/multi_phenos.txt', header=None)

# train data
train_df = genotype_df
label_df = pheno_df



K = 80 # feature number
train = train_df.as_matrix(feature_cols)
label = label_df.as_matrix().ravel()

def mic(x, y):
    m = MINE()
    m.compute_score(x, y)
    return (m.mic(), 0.5)
train = SelectKBest(lambda X, Y: np.array(map(lambda x:mic(x, Y), X.T)).T, k=K).fit_transform(train, label)

X_train, X_test, y_train, y_test = train_test_split(train, label, random_state=0, test_size=0.2)
