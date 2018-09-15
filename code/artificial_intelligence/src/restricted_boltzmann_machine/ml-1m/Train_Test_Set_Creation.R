dataset = read.csv('ratings.csv', header = FALSE)
colnames(dataset) = c("User","Movie","Rating","Timestamp")

library(caTools)
split = sample.split(dataset$User, SplitRatio = 0.75)
training_set = subset(dataset, split == TRUE)
test_set = subset(dataset, split == FALSE)

training_set = read.csv('training_set.csv')
test_set = read.csv('test_set.csv')

write.csv(training_set, "training_set.csv")
write.csv(test_set, "test_set.csv")