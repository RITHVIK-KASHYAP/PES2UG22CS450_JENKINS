pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                shh 'g++ -o output PES2UG22CS450.cpp' // Intentional typo in 'sh'
            }
        }

        stage('Test') {
            steps {
                sh './output'
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying application...'
            }
        }
    }

    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}
