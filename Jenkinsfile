pipeline
{
    agent
    {
        label 'incus-cpp-clang-jenkins-agent'
    }

    // Defines environment variables accessible throughout the pipeline.
    // These are used for common paths, names, and archive filenames.
    environment
    {
        BUILD_DIR         = 'build'
        EXECUTABLE_NAME   = 'jenkins-cpp-example'
        DOC_OUTPUT_DIR    = 'docs'
        DOC_ARCHIVE_NAME  = 'documentation.tar.gz'
    }

    stages
    {
        stage('Configure')
        {
            steps
            {
                // Create the build directory if it doesn't exist.
                sh "mkdir -p ${env.BUILD_DIR}"

                // Configure the project using CMake.
                sh "cmake -S . -B ${env.BUILD_DIR} -DCMAKE_BUILD_TYPE=Release"
            }
        }

        stage('Build')
        {
            steps
            {
                // Build the project via CMake.
                sh "cmake --build ${env.BUILD_DIR} --parallel \$(nproc)"
            }
        }

        stage('Run Application')
        {
            steps
            {
                script
                {
                    // The full path to the executable.
                    def executable_path = "${env.BUILD_DIR}/${env.EXECUTABLE_NAME}"

                    // Make the binary file executable. (optional)
                    sh "chmod +x ${executable_path}"

                    echo "Attempting to run: ${executable_path} --version"

                    sh "${executable_path} --version"

                    echo "Attempting to run: ${executable_path} --exit-success"

                    sh "${executable_path} --exit-success"
                }
            }
        }

        stage('Build Documentation')
        {
            steps
            {
                // Build documentation using Doxygen.
                sh 'doxygen doxyfile'

                // Check if the Doxygen output directory was actually created.
                sh "if [ ! -d '${env.DOC_OUTPUT_DIR}' ]; then echo 'Doxygen output directory ${env.DOC_OUTPUT_DIR} not found!'; exit 1; fi"

                // Check if the Doxygen output directory is empty.
                sh "if [ -z \"\$(ls -A '${env.DOC_OUTPUT_DIR}')\" ]; then echo 'Doxygen output directory ${env.DOC_OUTPUT_DIR} is empty!'; exit 1; fi"
            }
        }

        stage('Archive Artifacts')
        {
            steps
            {
                // Create a gzipped tar archive of the documentation.
                sh "tar -czvf ${env.DOC_ARCHIVE_NAME} -C ${env.DOC_OUTPUT_DIR} ."

                // Create artifacts with the executable and the documentation.
                archiveArtifacts artifacts: "${env.BUILD_DIR}/${env.EXECUTABLE_NAME}, ${env.DOC_ARCHIVE_NAME}", fingerprint: true
            }
        }
    }

    post
    {
        success
        {
            echo "Pipeline succeeded!"
        }

        failure
        {
            echo "Pipeline failed!"
        }

        always
        {
            echo "Pipeline finished."
            echo "Cleaning up build directory artifacts from workspace."

            // Jenkins step to clean the workspace.
            cleanWs()
        }
    }
}