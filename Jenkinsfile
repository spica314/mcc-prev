pipeline {
    agent none
    stages {
        stage('Check Pull Request') {
            agent any
            when {
                changeRequest target: 'master'
            }
            steps {
                sh 'git merge-base --is-ancestor origin/master $GIT_COMMIT'
            }
        }
        stage('Test') {
            agent {
                docker {
                    image 'alpine:latest'
                }
            }
            steps {
                sh 'apk add clang'
                sh './test.sh'
            }
        }
    }
}
