# P3CSN
A Performance Evaluation of Computer Systems and Networks Project developed during the academic year 2023/2024.

# Installation Guide

### 1. Download Files
Navigate to the **OMNeT++** Installation Folder and then in the folder where you want to save the project:
```bash
cd /path/to/folder
```
Run the git clone command to download the project repository:
```bash
git clone https://github.com/giovanniligato/P3CSN.git
```
Change the branch:
```bash
git checkout dev
```
### 2. Open the Project in OMNeT++ IDE. 
On the OMNeT++ IDE, click on **File** -> **Open Project From File System**, and select the **Quick_Checkout** folder within the cloned Git repository.

# Evaluation Feedback
During the evaluation an error was identified in the Project. Specifically, the *subsampling* of Waiting Times within a simulation was deemed unnecessary. The rationale behind this decision is that the correlation between Waiting Times is not a concern, as there is no requirement to calculate confidence intervals considering these Waiting Times. Indeed, The confidence intervals are computed based on the *Mean* Waiting Times of different repetitions conducted under independent conditions, making them uncorrelated. Therefore, all procedures related to the subsampling of Waiting Times, including the associated Python code and `vector` record type of the signals concerning Queuing Times, were deemed entirely unnecessary.