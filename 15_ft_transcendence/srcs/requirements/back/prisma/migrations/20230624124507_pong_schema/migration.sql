/*
  Warnings:

  - You are about to drop the column `Name` on the `ChannelUser` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "ChannelUser" DROP COLUMN "Name",
ADD COLUMN     "userID" INTEGER NOT NULL DEFAULT -1,
ADD COLUMN     "userName" TEXT NOT NULL DEFAULT 'unknown';

-- AddForeignKey
ALTER TABLE "ChannelUser" ADD CONSTRAINT "ChannelUser_userID_fkey" FOREIGN KEY ("userID") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
